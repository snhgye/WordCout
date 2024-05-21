#include <stdio.h>  
#include <stdlib.h>  
#include <ctype.h>  
#include <string.h>  
  
// 函数声明  
int count_characters(const char *filename);  
int count_words(const char *filename);  
  
int main(int argc, char *argv[]) {  
    if (argc != 3) {  
        fprintf(stderr, "Usage: %s [-c|-w] [input_file_name]\n", argv[0]);  
        return 1;  
    }  
  
    // 检查参数  
    if (strcmp(argv[1], "-c") == 0) {  
        printf("字符数：%d\n", count_characters(argv[2]));  
    } else if (strcmp(argv[1], "-w") == 0) {  
        printf("单词数：%d\n", count_words(argv[2]));  
    } else {  
        fprintf(stderr, "Invalid parameter: %s\n", argv[1]);  
        return 1;  
    }  
  
    return 0;  
}  
  
// 统计字符数  
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
  
// 统计单词数  
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
        // 跳过非字母数字字符，除了空格、逗号和换行符  
        if (isspace(ch) || ch == ',') {  
            if (in_word) {  
                count++;  
                in_word = 0;  
            }  
        } else {  
            in_word = 1;  
        }  
    }  
  
    // 检查文件末尾是否有单词  
    if (in_word) {  
        count++;  
    }  
  
    fclose(file);  
    return count;  
}
