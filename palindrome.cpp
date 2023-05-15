#include <iostream>
#include <string>

int main(){
    int begining, end;
    bool change, is_pal;
    std::string str("\0");
    while(true) {
        std::cin >> str;
        if (str == "0") break;
        begining = 0;
        is_pal = true;
        change = false;
        end = (str.size()) - 1;

        while(begining < end){
            if(str[begining] != str[end]){
                if(!change){
                    if(str[begining + 1] == str[end]){
                        ++begining;
                        change = true;
                    }
                    else if(str[begining] == str[end - 1]){
                        --end;
                        change = true;
                    }
                    else{
                        is_pal = false;
                        break;
                    }
                }
                else{
                    is_pal = false;
                    break;
                }
            }
            ++begining;
            --end;
        }
        if((is_pal) && (change)){
            is_pal = false;
        }
        if (is_pal) {
            puts("yes");
        }
        else {
            puts("no");
        }
    }

    return 0;
}