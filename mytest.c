#include <string.h>

#include "m_ctype.h"

int main() {
  char str1[] = "opu7EuA-fC8-ZW3mfo9hHUz43Agg";
  char str2[] = "opu7EuA-HzXxRl58Z8yGdOeTNi0E";
  char str3[] = "opu7EuA-RW1nVvcGFjKPHH04N-1c";
  char str4[] = "opu7EuA-_9Xs6df2tbwIBxC26sBM";
  char str5[] = "opu7EuA0OfNdEKfXqNkthrTgRgO8";

  char *p[] = {str1, str2, str3, str4, str5};
  int i, j;
  int len = sizeof(p) / sizeof(char*);

  for (i = 0; i < len ; i++) {
    for (j =i+1; j < len; j++) {
      int ret =
        my_charset_utf8_general_ci.coll->strnncollsp(&my_charset_utf8_general_ci,
            p[i], strlen(p[i]),
            p[j], strlen(p[j]),
            0);
      if (ret  == 1) {
        char *s = p[i];
        p[i] = p[j];
        p[j] = s;
      }
    }
  }

  printf("Sort result with asc order :\n");
  for (i = 0; i < len; i++) {
    printf("%s\n", p[i]);
  }
  return 0;
}
