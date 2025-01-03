#include <stdio.h>

struct xc {
  char n[20], p[20];
  int a, p;
  char COD[11];
};

int main() {
  struct xc c  = {"Xxxx", "Xxxx", "99", "99999", "32222236655"};
  struct xc dda = {"XXXX", "XXXX", "89", "99999", "32222236655"};
  printf("Nom : %s\nPrenom : %s\nAge : %s \nCode Postal : %s\nINE : %s\n\n\n\n\n\n", c.n, c.p, c.a, c.p, c.COD);
  printf("Nom : %s\nPrenom : %s\nAge : %s \nCode Postal : %s\nINE : %s\n\n\n\n\n\n", dda.n, dda.p, dda.a, dda.p, dda.COD);

  return 0;
}
