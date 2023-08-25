#include <iostream>
#include <cstring>
#include <algorithm>

#define CURCHANNEL 100
typedef struct {
	bool match;
	char last;
	char next;
}NumInfo;

int getDiff(int a, int b) {
	int diff = a - b;
	if (diff < 0) diff *= -1;
	return diff;
}

int countZeros(char* number) {
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

void setButtons(char* brokenButtons, int brokenButtonSize, char* workingButtons, NumInfo* numInfo) {
	for (int i = 0; i < brokenButtonSize; ++i) {
		getchar();
		scanf_s("%c", &brokenButtons[i], 1);
	}
	const char buttons[]{ "0123456789" };
	int buttonCount = 0;
	int brokenIdx = 0;
	for (int i = 0; buttons[i] != '\0'; ++i) {
		if (brokenIdx == brokenButtonSize) {
			for (int j = buttons[i]; j <= '9'; ++j) {
				workingButtons[buttonCount++] = j;
				numInfo[j-'0'].match = true;
			}
			break;
		}
		if (buttons[i] < brokenButtons[brokenIdx]) {
			workingButtons[buttonCount++] = buttons[i];
			numInfo[buttons[i]-'0'].match = true;
		}
		else {
			++brokenIdx;
			numInfo[buttons[i]-'0'].match = false;
		}
	}

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

int calcButtonPressCount(char* targetChannel, char* workingButtons, int workingButtonSize, NumInfo* numInfo) {
	int target = std::atoi(targetChannel);
	int buttonCount = 0;
	int result = getDiff(target, CURCHANNEL);
	if (workingButtonSize > 0) {
		int targetLength = strlen(targetChannel);
		char* tempChannel = new char[targetLength+2];
		int resultByButton = -1;
		int tempChannelLength = targetLength;
		for (int i = 0; i < targetLength; ++i) {
			if (numInfo[targetChannel[i] - '0'].match) {
				tempChannel[buttonCount++] = targetChannel[i];
			}
			else {
				char* tempChannel2 = new char[targetLength+2];
				std::copy(tempChannel, tempChannel + buttonCount, tempChannel2);
				if (i == 0 && targetLength > 1) {
					if (targetChannel[i] > workingButtons[workingButtonSize - 1]) {
						if (workingButtons[0] == '0') {
							tempChannel[0] = workingButtons[1 % workingButtonSize];
						}
						else {
							tempChannel[0] = workingButtons[0];
						}
						tempChannel[targetLength] = workingButtons[0];
						tempChannelLength = targetLength + 1;
						tempChannel2[0] = numInfo[targetChannel[i] - '0'].last;
					}
					else if (targetChannel[i] < workingButtons[0]) {
						tempChannel2[0] = '0';
						tempChannel[0] = workingButtons[0];
					}
					else {
						tempChannel[i] = numInfo[targetChannel[i] - '0'].next;
						tempChannel2[i] = numInfo[targetChannel[i] - '0'].last;
					}
				}
				else {
					tempChannel[i] = numInfo[targetChannel[i] - '0'].next;
					tempChannel2[i] = numInfo[targetChannel[i] - '0'].last;
				}
				if (i < targetLength - 1) {
					for (int j = i+1; j < targetLength; ++j) {
						tempChannel[j] = workingButtons[0];
						tempChannel2[j] = workingButtons[workingButtonSize-1];
					}
				}
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
	int workingButtonSize = 0;
	scanf_s("%s", targetChannel, 7);
	scanf_s("%d", &brokenButtonSize);
	
	char* brokenButtons = new char[brokenButtonSize];
	workingButtonSize = 10 - brokenButtonSize;
	char* workingButtons = new char[workingButtonSize];

	NumInfo numInfo[10]{0};
	setButtons(brokenButtons, brokenButtonSize, workingButtons, numInfo);
	printf("%d\n", calcButtonPressCount(targetChannel, workingButtons, workingButtonSize, numInfo));
	delete[] brokenButtons;
	delete[] workingButtons;
}