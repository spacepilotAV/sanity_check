int INSANE        = 0;
int FAIL_OVERFLOW = 1;
int FAIL_MODULO   = 2;
int FAIL_WTFCHAR  = 3;
int FAIL_WTFCHAR2 = 4;
int FAIL_WTFCHAR3 = 5;
int FAIL_WTFCHAR4 = 6;
int FAIL_WTFCHAR5 = 7;


int check_overflow() {
  char buf[1];
/*  buf[2] = 0x41;
  if (buf[2] != 0x41)
    SANITY = FAIL_OVERFLOW;
*/  return INSANE;
}

int check_modulo() {
  int i = 0;
  for (int j = 0; j < 1048576; j++) {
    i += j;
    i *= j;
    i %= j;
  }
  if (i != 'w')
    INSANE = FAIL_MODULO;
  return INSANE;
}

int check_char() {
  if ('a' != 'a')
    INSANE=FAIL_WTFCHAR;
  char a = 'a';
  if (a != 'a')
    INSANE=FAIL_WTFCHAR2;
  if (a != a)
    INSANE=FAIL_WTFCHAR3;
  char b = 'a';
  char c = 'b';
  if (a != b)
    INSANE=FAIL_WTFCHAR4;
  if (a == c)
    INSANE=FAIL_WTFCHAR5;
  return INSANE;
}

int sanity() {
  check_overflow();
  if (INSANE)
    return INSANE;
  check_modulo();
  if (INSANE)
    return INSANE;
  check_char();
  if (INSANE)
    return INSANE;
  return 0;
}
