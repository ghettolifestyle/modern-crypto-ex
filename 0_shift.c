#include <stdio.h>
#include <strings.h>

int get_index(char character, char* set) {
  int index;

  for (int i = 0; i < strlen(set); i++) {
    if (character == set[i]) {
      index = i;
      break;
    }
  }
    return index;
}

void decrypt_ciphertext(char* message) {
  char alphabet[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  short current;
  short new;

  printf("input: %s\n\n", message);

  for (int k = 1; k < strlen(alphabet); k++) {
    printf("k = %2d ", k);

    for (int j = 0; j <= strlen(message); j++) {
      current = get_index(message[j], alphabet);
      new = current + k;

      if (new >= 26)
        new = new - 26;

      printf("%c", alphabet[new]);
    }
    printf("\n");
  }
}

int main() {
  decrypt_ciphertext("OVDTHUFWVZZPISLRLFZHYLAOLYL");
}
