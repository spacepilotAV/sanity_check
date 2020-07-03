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
  buf[2] = 0x41;
  if (buf[2] != 0x41)
    SANITY = FAIL_OVERFLOW;
  return SANITY;
}

int check_modulo() {
  int i = 0;
  for (int j = 0; j < 1048576; j++) {
    i += j;
    i *= j;
    i %= j;
  }
  if (i != 'w')
    SANITY = FAIL_MODULO;
  return SANITY;
}

int check_char() {
  if ('a' != 'a')
    SANITY=FAIL_WTFCHAR;
  char a = 'a';
  if (a != 'a')
    SANITY=FAIL_WTFCHAR2;
  if (a != a)
    SANITY=FAIL_WTFCHAR3;
  char b = 'a';
  char c = 'b';
  if (a != b)
    SANITY=FAIL_WTFCHAR4;
  if (a == c)
    SANITY=FAIL_WTFCHAR5;
  return SANITY;
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
