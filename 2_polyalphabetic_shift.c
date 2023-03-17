// constraint:
// - both key and input must be uppercase, no spaces
// - both key and input are harcoded, should be scanf'd but i was too lazy

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
  // hans niemann?
  char key[] = "BEADS";
  int key_offset;
  int key_length;
  int old_index;
  int new_index;
  int sum;

  printf("%s\n", message);

  for (int i = 0; i < strlen(message); i++) {
    key_offset = i;
    key_length = strlen(key);

    if (key_offset >= key_length)
      key_offset = key_offset % key_length;

    //printf("%c %d\n", key[key_offset], get_index(key[key_offset], alphabet));

    old_index = get_index(message[i], alphabet);
    new_index = old_index + get_index(key[key_offset], alphabet);
    
    if (new_index >= 26)
      new_index = new_index - 26;

    //printf("%d %c -> %d %c\n", old_index, alphabet[old_index], new_index, alphabet[new_index]);
    printf("%c", alphabet[new_index]);
  }
  printf("\n");

}

int main() {
  decrypt_ciphertext("THEMANANDTHEWOMANRETRIEVEDTHELETTERFROMTHEPOSTOFFICE");
}
