#include <stdio.h>  
#include <stdlib.h>  
#include <ctype.h>  
#include <string.h>  
  
// ��������  
int count_characters(const char *filename);  
int count_words(const char *filename);  
  
int main(int argc, char *argv[]) {  
    if (argc != 3) {  
        fprintf(stderr, "Usage: %s [-c|-w] [input_file_name]\n", argv[0]);  
        return 1;  
    }  
  
    // ������  
    if (strcmp(argv[1], "-c") == 0) {  
        printf("�ַ�����%d\n", count_characters(argv[2]));  
    } else if (strcmp(argv[1], "-w") == 0) {  
        printf("��������%d\n", count_words(argv[2]));  
    } else {  
        fprintf(stderr, "Invalid parameter: %s\n", argv[1]);  
        return 1;  
    }  
  
    return 0;  
}  
  
// ͳ���ַ���  
int count_characters(const char *filename) {  
    FILE *file = fopen(filename, "r");  
    if (!file) {  
        perror("Error opening file");  
        return -1;  
    }  
  
    int count = 0;  
    char ch;  
    while ((ch = fgetc(file)) != EOF) {  
        count++;  
    }  
  
    fclose(file);  
    return count;  
}  
  
// ͳ�Ƶ�����  
int count_words(const char *filename) {  
    FILE *file = fopen(filename, "r");  
    if (!file) {  
        perror("Error opening file");  
        return -1;  
    }  
  
    int count = 0;  
    int in_word = 0;  
    char ch;  
  
    while ((ch = fgetc(file)) != EOF) {  
        // ��������ĸ�����ַ������˿ո񡢶��źͻ��з�  
        if (isspace(ch) || ch == ',') {  
            if (in_word) {  
                count++;  
                in_word = 0;  
            }  
        } else {  
            in_word = 1;  
        }  
    }  
  
    // ����ļ�ĩβ�Ƿ��е���  
    if (in_word) {  
        count++;  
    }  
  
    fclose(file);  
    return count;  
}
