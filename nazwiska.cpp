#include <stdio.h>
#include <string.h>

void main( void )
{
  FILE *plik;
  char strtmp[ 501 ];
  char nazwisko[ 501 ];
  int res;
  int index;
  char Nazwiska[100][501];
  int i,j;

  plik = fopen("nazwiska.txt", "rt");
  if(plik==NULL)
  {
    printf("B³¹d odczytu pliku\n");
    return 0;
  }
  index=0;
  while((!feof(plik))&&(index<100))
  {
   
    res=fscanf(plik,"%s",nazwisko);
    if(res!=1)
    {
      printf("B³¹d odczytu");
      break;
    }
    strcpy(Nazwiska[index],nazwisko);
    index++;
  }
  fclose( plik);
  for(i=0;i<index;i++)
  {
    for(j=0;j<index-i-1;j++)
    {
      if(strcmp(Nazwiska[j],Nazwiska[j+1])>0)
      {
    
        strcpy(strtmp,Nazwiska[j]);
        strcpy(Nazwiska[j],Nazwiska[j+1]);
        strcpy(Nazwiska[j+1],strtmp);
      }
    }
  }

  plik = fopen("nazwiska_leksyko.txt", "w+t");
  if(plik==NULL)
  {
    printf("B³¹d otwarcia pliku\n");
    return 0;
  }
  for(i=0;i<index;i++)
  {
    fprintf(plik,"%s ",Nazwiska[i]);
    fprintf(plik,"\n");
  }
  fclose( plik );

  return;
}
