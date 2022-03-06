#include <assert.h>
#include <stdio.h>
#include <stdlib.h>



typedef struct _list {
  int other;
  int relation;
  struct _list* next;
} list;

int reciprocal[4] = {0, 2, 1, 3};
int n;
list* clauses[110];
int sol[110];
int seen[110];

void link(int x, int y, int r) {
  list* l = (list*)malloc(sizeof(list));
  l->other = y;
  l->relation = r;
  l->next = clauses[x];
  clauses[x] = l;
}

void read() {
  FILE* f = fopen("party.in", "rt");
  int m;
  fscanf(f, "%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    clauses[i] = NULL;
  }
  while (m--) {
    int x, y, r;
    fscanf(f, "%d %d %d", &x, &y, &r);
    link(x, y, r);
    link(y, x, reciprocal[r]);
  }
  fclose(f);
}

void traverse(int x, int value) {
  if (sol[x] != -1) {
    assert(sol[x] == value);
    return;
  }
  sol[x] = value;
  for (list* l = clauses[x]; l; l = l->next) {
    if (value == (l->relation >> 1)) {
      traverse(l->other, !(l->relation & 1));
    }
  }
}

int closure(int x, int originalX, int value) {
  if (seen[x] != -1) {
    return (seen[x] != value);
  }
  seen[x] = value;
  for (list* l = clauses[x]; l; l = l->next) {
    if (value == (l->relation >> 1)) {
      if (closure(l->other, originalX, !(l->relation & 1))) {
        return 1;
      }
    }
  }
  return 0;
}



int xToNotX(int x) {
  for (int i = 1; i <= n; i++) {
    seen[i] = -1;
  }
  return closure(x, x, 1);
}

void assign() {
  for (int i = 1; i <= n; i++) {
    sol[i] = -1;
  }
  for (int i = 1; i <= n; i++) {
    if (sol[i] == -1) {
      if (xToNotX(i)) {
        traverse(i, 0);
      } else {
        traverse(i, 1);
      }
    }
  }
}

void write() {
  FILE* f = fopen("party.out", "wt");
  int numComing = 0;
  for (int i = 1; i <= n; i++) {
    numComing += sol[i];
  }
  fprintf(f, "%d\n", numComing);
  for (int i = 1; i <= n; i++) {
    if (sol[i]) {
      fprintf(f, "%d\n", i);
    }
  }
  fclose(f);
}

int main() {
  read();
  assign();
  write();
  return 0;
}
