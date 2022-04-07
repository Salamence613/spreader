#ifndef SPREADER_H
#define SPREADER_H

#include "spreaderRunner.h"

class Person2
{
  public:
     int numVisitors; //-1 for known
     Visitor* visitors;
     int dv;
};

class Person2ListNode
{
  public:
    Person2ListNode(Person2* p = NULL, Person2ListNode* n = NULL) : me(p), next(n) {}
    Person2* me;
    Person2ListNode* next;
};

class Person2List
{
  public:
    Person2List() {root = new Person2ListNode;}
    void insert(Person2* p)
    {
      root->next = new Person2ListNode(p, root->next);
    }
    void remove(void)
    {
      Person2ListNode* old = root->next;
      root->next = root->next->next;
      delete old;
    }
    Person2ListNode* root;
};

class Spreader
{
  public:
    int day;
    int pop;
    Person2* people2;
    Spreader(const Person *people, int population);
    int simulate(int starterIDs[], int starterCount, int commandLineOption);
};

#endif /* SPREADER_H */
