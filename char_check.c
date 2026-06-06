#include <stdio.h>
#include <stdlib.h>

int main(){
  char str[1000001];
  scanf("%s",str);
  int sflag = 0;
  int lflag = 0;
  int nflag = 0;

  for(int i =0 ;str[i];i++){
    char ch = str[i];
    if(ch>='a' && ch<='z'){
      sflag = sflag|(1<<(ch - 'a'));
    }else if (ch>='A' && ch<='Z') {
      lflag = lflag|(1<<(ch - 'A'));
    }else{
      nflag = nflag|(1<<(ch-'0'));
    }
  }
  printf((sflag==(1<<26)-1)?"Yes":"No");
  printf((lflag==(1<<26)-1)?"Yes":"No");
  printf((nflag==(1<<10)-1)?"Yes":"No");
  return 0;
}
