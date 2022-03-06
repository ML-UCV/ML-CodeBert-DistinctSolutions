#include <assert.h>
#include <stdio.h>
#include <string.h>

enum { maxpers = 101, maxrules = 1001 };
enum status { none = 0, must_be, must_not_be };

int pers;
int depcount[maxpers];
int depwho[maxpers][maxpers];
status dep[maxpers][maxpers];
int mustcount;
int must[maxrules][2];

status stat[maxpers];

int k;

bool mark(int who, status what)
{
 printf("mark %d with %d\n", who, what);

 int i;

 assert(what == must_be || what == must_not_be);

 if(stat[who] != none && stat[who] != what)
  return false;

 if(stat[who] == what)
  return true;

 stat[who] = what;

 if(what == must_be)
 {
  for(i = 0; i < depcount[who]; i++)
   if(!mark( depwho[who][i], dep[who][i] ))
    return false;
 }


 return true;
}

bool bkt_must()
{
 status stat_copy[maxpers];
 memcpy(stat_copy, stat, sizeof(stat));

 printf("bkt_must k %d, stat: ", k);
 for(int i = 0; i < pers; i++)
  printf("%d ", stat[i]);
 printf("\n");

 if(k == mustcount)
  return true;

 if(stat[ must[k][0] ] == must_be && stat[ must[k][1] ] == must_be)
 {
  printf("must_be must_be\n");

  k++;
  if(bkt_must())
   return true;
  k--;
 }
 else if(stat[ must[k][0] ] == must_be && stat[ must[k][1] ] != must_be)
 {
  printf("must_be ?\n");

  k++;
  if(bkt_must())
   return true;
  k--;

  if(mark( must[k][1], must_be ))
  {
   k++;
   if(bkt_must())
    return true;
   k--;
  }
  memcpy(stat, stat_copy, sizeof(stat));
 }
 else if(stat[ must[k][0] ] != must_be && stat[ must[k][1] ] == must_be)
 {
  printf("? must_be\n");

  k++;
  if(bkt_must())
   return true;
  k--;

  if(mark( must[k][0], must_be ))
  {
   k++;
   if(bkt_must())
    return true;
   k--;
  }
  memcpy(stat, stat_copy, sizeof(stat));
 }
 else if(stat[ must[k][0] ] != must_be && stat[ must[k][1] ] != must_be)
 {
  printf("? ?\n");

  if(mark( must[k][0], must_be ))
  {
   k++;
   if(bkt_must())
    return true;
   k--;
  }
  memcpy(stat, stat_copy, sizeof(stat));

  if(mark( must[k][1], must_be ))
  {
   k++;
   if(bkt_must())
    return true;
   k--;
  }
  memcpy(stat, stat_copy, sizeof(stat));

  if(mark( must[k][0], must_be ) && mark( must[k][1], must_be ))
  {
   k++;
   if(bkt_must())
    return true;
   k--;
  }
  memcpy(stat, stat_copy, sizeof(stat));
 }

 return false;
}

void go()
{


 if(bkt_must())
  return;

 for(int start = 0; start < pers; start++)
 {
  printf("\n\nstart %d --------------------------------------------\n", start);
  memset(stat, 0, sizeof(stat));

  if(!mark( start, must_be ))
   continue;

  assert(k == 0);
  if(bkt_must())
   return;
 }


 assert(false && "no solution!");
}

void validate_rules()
{
 int i, rules, a, b, type, shit;
 FILE *f = fopen("party.in", "r");
 assert(f);

 fscanf(f, "%d%d", &shit, &rules);
 for(i = 0; i < rules; i++)
 {
  int damn = fscanf(f, "%d%d%d", &a, &b, &type);
  assert(damn == 3);
  a--; b--;

  switch(type)
  {
   case 0:
    assert(stat[a] == must_be || stat[b] == must_be);
    break;
   case 1:
    if(stat[b] == must_be)
     assert(stat[a] == must_be);
    break;
   case 2:
    if(stat[a] == must_be)
     assert(stat[b] == must_be);
    break;
   case 3:
    if(stat[a] == must_be)
     assert(stat[b] == must_not_be);
    else if(stat[a] == must_be)
     assert(stat[a] == must_not_be);
    break;
   default:
    assert(false);
  }
 }

 fclose(f);
}

int main()
{
 int i, rules, a, b, type, count;
 FILE *f = fopen("party.in", "r");
 if(!f) return 1;

 fscanf(f, "%d%d", &pers, &rules);
 for(i = 0; i < rules; i++)
 {
  int damn = fscanf(f, "%d%d%d", &a, &b, &type);
  assert(damn == 3);
  a--; b--;

  switch(type)
  {
   case 0:
    must[mustcount][0] = a;
    must[mustcount][1] = b;
    mustcount++;
    break;
   case 1:
    depwho[b][ depcount[b] ] = a;
    dep[b][ depcount[b] ] = must_be;
    depcount[b]++;

    break;
   case 2:
    depwho[a][ depcount[a] ] = b;
    dep[a][ depcount[a] ] = must_be;
    depcount[a]++;

    break;
   case 3:
    depwho[a][ depcount[a] ] = b;
    dep[a][ depcount[a] ] = must_not_be;
    depcount[a]++;

    depwho[b][ depcount[b] ] = a;
    dep[b][ depcount[b] ] = must_not_be;
    depcount[b]++;

    break;
   default:
    assert(false);
  }
 }

 fclose(f);
 f = fopen("party.out", "w");
 if(!f) return 1;

 go();
 validate_rules();

 count = 0;
 for(i = 0; i < pers; i++)
  if(stat[i] == must_be)
   count++;

 fprintf(f, "%d\n", count);

 for(i = 0; i < pers; i++)
  if(stat[i] == must_be)
   fprintf(f, "%d\n", i + 1);

 fclose(f);
 return 0;
}
