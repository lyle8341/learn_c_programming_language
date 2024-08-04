# 字符串处理函数

+ 自定义strlen
  + v1
    ```c
    size_t my_strlen(const char *str) {//不修改传进来的参数，值不能改
        int cnt = 0;
        while (*str != '\0') {
            //前置++效率高一些
            ++str;
            ++cnt;
        }
        return cnt;
    }
    ```
  + v2
    ```c
    size_t my_strlen(const char *str) {//不修改传进来的参数，值不能改
        const char *start = str; //把开始位置记录一下
        while (*str != '\0') {
            //前置++效率高一些
            ++str;
        }
        return str - start;
    }
    ```
    
+ 自定义strcpy
  ```c
  char *my_strcpy(char *dest, const char *src) {
      char *start = dest;
      while (*src != '\0') {
          *dest++ = *src++;
      }
      *dest = '\0';
      return start;//指针偏移后重置
  }
  ```
  
+ 自定义strcat
  ```c
  char *my_strcat(char *dest, const char *src) {
      char *start = dest;
      while (*dest++ != '\0');//dest指向\0
      dest--;
      while (*src != '\0') {
          *dest++ = *src++;
      }
      *dest = '\0';
      return start; //重置偏移
  }
  ```
  
+ 自定义strcmp
  ```c
  int my_strcmp(const char *str1, const char *str2) {
      while (*str1 && *str2) { //!='\0'
          if (*str1 != *str2)
              break;
          str1++;
          str2++;
      }
      if (*str1 - *str2 > 0) {
          return 1;
      } else if (*str1 - *str2 == 0) {
          return 0;
      } else {
          return -1;
      }
  }
  ```