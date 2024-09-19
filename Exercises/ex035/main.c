
int main(void) {

  int v[10], i;
  int n = 1;

  for(i = 0; i < 10; i++){
    v[i] = n;
    n += 2;
    printf("\n%d", v[i]);
  }

return 0;
}
  