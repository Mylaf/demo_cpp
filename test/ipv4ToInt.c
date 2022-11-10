#include <stdio.h>

int ipStr_2_int(char* str);

int main(){
    // OK
    printf("OK:\n");
    ipStr_2_int("255.254.253.252");
    ipStr_2_int("0.0.0.");
    ipStr_2_int("255...1");
    ipStr_2_int("10.10.2.10");
    ipStr_2_int("...");
    ipStr_2_int("255.255.255.255");
    ipStr_2_int("1.1.1.");
    ipStr_2_int(".1.1.");
    
    // invalid 
    printf("invalid:\n");
    ipStr_2_int("0.FF.0.0");
    ipStr_2_int("0.1A.222.192");
    ipStr_2_int("1.1.1");
    //
    printf("finish.\n");
    return 0;
}

int ipStr_2_int(char* str){
    char *p = str, c = 0;
    int v = 0;
    int shift = 24, one = 0, dot = 0;
    while (((*p) != '\0') && (shift > -1)){
        c = *p;
        if (c>='0' && c<='9'){
            one *= 10;
            one += c-'0';
        }
        else {
            if (c != '.'){
                v = -1;
                printf("%s > %d (0x%X) \n", str, v, v);
                return v;
            }
            else{
                dot++;
            }
            v += (one << shift);
            shift -= 8;
            one = 0;
        }
        // next
        ++p;
    }
    if (dot != 3){
        v = -1;
        printf("%s > %d (0x%X) \n", str, v, v);
        return v;
    }

    if (shift > -1){
    //if (one != 0){
        v += (one << shift);
        shift -= 8;
        one = 0;
    }
    printf("%s > 0x%08X \n", str, v);
    return v;
}
