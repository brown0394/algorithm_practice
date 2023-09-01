#include <iostream>
#include <cstring>
#include <algorithm>

#define CURCHANNEL 100
typedef struct {
	bool match;
	char last;
	char next;
}NumInfo;

class RemoteController {
private:
	char targetChannel[7];
	int brokenButtonSize;
	int workingButtonSize;
	char* brokenButtons;
	char* workingButtons;
	NumInfo numInfo[10];
	int getDiff(int a, int b);
	int countZeros(char* number);
	int setMatch();
	void setButtons();
	int addUp(char* arr, int cur);
	int subtractDown(char* arr, int cur);
	void processUnmatch(char* tempChannel, char* tempChannel2, int& tempChannelLength, int targetChannel, int idx);
public:
	RemoteController(int p_brokenButtonSize, int p_workingButtonSize, char* p_targetChannel);
	~RemoteController();
	int calcButtonPressCount();
};

RemoteController::RemoteController(int p_brokenButtonSize, int p_workingButtonSize, char* p_targetChannel) : brokenButtonSize(p_brokenButtonSize),
workingButtonSize(p_workingButtonSize) {
	brokenButtons = new char[brokenButtonSize];
	workingButtons = new char[workingButtonSize];
	std::copy(p_targetChannel, p_targetChannel + 7, targetChannel);
}

RemoteController::~RemoteController() {
	delete[] brokenButtons;
	delete[] workingButtons;
}

int RemoteController::getDiff(int a, int b) {
	int diff = a - b;
	if (diff < 0) diff *= -1;
	return diff;
}

int RemoteController::countZeros(char* number) {
	int count = 0;
	bool isAllZero = true;
	while (*number != '\0') {
		if (*number > '0') {
			isAllZero = false;
			break;
		}
		++count;
		++number;
	}
	if (isAllZero) --count;
	return count;
}

int RemoteController::addUp(char* arr, int cur) {
	int size = cur;
	if (cur == 0) {
		if (workingButtons[0] == '0') {
			arr[0] = workingButtons[1 % workingButtonSize];
		}
		else {
			arr[0] = workingButtons[0];
		}
		return 1;
	}
	arr[cur--] = workingButtons[0];
	while (cur >= 0) {
		if (arr[cur] == workingButtons[workingButtonSize - 1]) {
			arr[cur] = workingButtons[0];
		}
		else {
			if (numInfo[arr[cur]+1].match) {
				++arr[cur];
			}
			else {
				arr[cur] = numInfo[arr[cur]].next;
			}
			break;
		}
		--cur;
	}
	if (cur < 0) {
		std::copy(arr, arr + size, arr + 1);
		if (workingButtons[0] == '0') {
			arr[0] = workingButtons[1 % workingButtonSize];
		}
		else {
			arr[0] = workingButtons[0];
		}
		return 1;
	}
	return 0;
}

int RemoteController::subtractDown(char* arr, int cur) {
	if (cur == 0) {
		arr[0] = '0';
		return 1;
	}
	arr[cur--] = workingButtons[workingButtonSize - 1];
	while (cur >= 0) {
		if (arr[cur] == workingButtons[0]) {
			if (cur == 0) {
				arr[0] = '0';
			}
			arr[cur] = workingButtons[workingButtonSize - 1];
		}
		else {
			if (numInfo[arr[cur] - '0' - 1].match) {
				--arr[cur];
			}
			else {
				arr[cur] = numInfo[arr[cur] - '0' - 1].last;
			}
			break;
		}
		--cur;
	}
	return 1;
}

int RemoteController::setMatch() {
	for (int i = 0; i < brokenButtonSize; ++i) {
		getchar();
		scanf_s("%c", &brokenButtons[i], 1);
	}
	const char buttons[]{ "0123456789" };
	int buttonCount = 0;
	int brokenIdx = 0;
	std::sort(brokenButtons, brokenButtons + brokenButtonSize);
	for (int i = 0; buttons[i] != '\0'; ++i) {
		if (brokenIdx == brokenButtonSize) {
			for (int j = buttons[i]; j <= '9'; ++j) {
				workingButtons[buttonCount++] = j;
				numInfo[j - '0'].match = true;
			}
			break;
		}
		if (buttons[i] < brokenButtons[brokenIdx]) {
			workingButtons[buttonCount++] = buttons[i];
			numInfo[buttons[i] - '0'].match = true;
		}
		else {
			++brokenIdx;
			numInfo[buttons[i] - '0'].match = false;
		}
	}
	return buttonCount;
}
void RemoteController::setButtons() {

	int buttonCount = setMatch();
	if (buttonCount > 0) {
		char lastWorkingButton = workingButtons[buttonCount-1];
		int WorkingButtonIdx = 0;
		for (int i = 0; i < 10; ++i) {
			if (numInfo[i].match) {
				lastWorkingButton = i + '0';
				WorkingButtonIdx = (WorkingButtonIdx + 1) % buttonCount;
			}
			else {
				numInfo[i].last = lastWorkingButton;
				numInfo[i].next = workingButtons[WorkingButtonIdx];
			}
		}
	}

}

void RemoteController::processUnmatch(char* tempChannel, char* tempChannel2, int& tempChannelLength, int targetLength, int idx) {
	if (targetChannel[idx] > workingButtons[workingButtonSize - 1]) {
		if (addUp(tempChannel, idx)) {
			tempChannel[tempChannelLength++] = workingButtons[0];
		}
		tempChannel2[idx] = numInfo[targetChannel[idx] - '0'].last;
	}
	else if (targetChannel[idx] < workingButtons[0]) {
		tempChannel[idx] = workingButtons[0];
		subtractDown(tempChannel2, idx);
	}
	else {
		tempChannel[idx] = numInfo[targetChannel[idx] - '0'].next;
		tempChannel2[idx] = numInfo[targetChannel[idx] - '0'].last;
	}
	if (idx < targetLength - 1) {
		for (int j = idx + 1; j < targetLength; ++j) {
			tempChannel[j] = workingButtons[0];
			tempChannel2[j] = workingButtons[workingButtonSize - 1];
		}
	}
}

int RemoteController::calcButtonPressCount() {
	setButtons();
	int target = std::atoi(targetChannel);
	int buttonCount = 0;
	int result = getDiff(target, CURCHANNEL);
	if (workingButtonSize > 0) {
		int targetLength = strlen(targetChannel);
		char* tempChannel = new char[targetLength+2];
		int resultByButton = -1;
		int tempChannelLength = targetLength;
		for (int i = 0; i < targetLength; ++i) {
			if (numInfo[targetChannel[i] - '0'].match) {//when it matches just put the number.
				tempChannel[buttonCount++] = targetChannel[i];
			}
			else {//when it does not match
				char* tempChannel2 = new char[targetLength+2];
				std::copy(tempChannel, tempChannel + buttonCount, tempChannel2);
				processUnmatch(tempChannel, tempChannel2, tempChannelLength, targetLength, i);
				tempChannel[tempChannelLength] = '\0';
				tempChannel2[targetLength] = '\0';
				int diff1 = getDiff(std::atoi(tempChannel), target) + tempChannelLength - countZeros(tempChannel);;
				int diff2 = getDiff(std::atoi(tempChannel2), target) + targetLength - countZeros(tempChannel2);
				if (diff1 <= diff2) {
					resultByButton = diff1;
				}
				else {
					resultByButton = diff2;
				}
				delete[] tempChannel2;
				break;
			}
		}
		if (resultByButton < 0) {
			resultByButton = targetLength;
		}
		if (resultByButton < result) {
			result = resultByButton;
		}
		delete[] tempChannel;
	}

	return result;
}

int main() {
	char targetChannel[7];
	int brokenButtonSize = 0;
	scanf_s("%s", targetChannel, 7);
	scanf_s("%d", &brokenButtonSize);
	
	RemoteController remoteCont(brokenButtonSize, 10 - brokenButtonSize, targetChannel);

	printf("%d\n", remoteCont.calcButtonPressCount());
}