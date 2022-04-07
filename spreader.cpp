#include <iostream>  // for debugging
#include <cstring>
#include "spreader.h"
#define BIG_NUM 32768
#define MAX_DV 1000
// using namespace std;

Spreader::Spreader(const Person *people, int population)
{
  // Students write this.
  // Note that people will be deleted before simulate() is called.
  day = 3;
  pop = population;
  people2 = new Person2[population];
  for(int i = 0; i < population; i++)
  {
    people2[i].numVisitors = people[i].peopleMet;
    people2[i].visitors = new Visitor[people[i].peopleMet];
    memcpy(people2[i].visitors, people[i].visitors, sizeof(Visitor) * people[i].peopleMet);
    people2[i].dv = BIG_NUM;
  }
} // Spreader()

int Spreader::simulate(int starterIDs[], int starterCount, int commandLineOption)
{
  // commandLineOption may be used to signal the program to do whatever the students
  // want, or nothing at all.
  Person2List* personListArr = new Person2List[MAX_DV];

  for(int i = 0; i < starterCount; i++)
  {
    people2[starterIDs[i]].dv = INCUBATION_TIME;
    personListArr[INCUBATION_TIME].insert(&people2[starterIDs[i]]);
  }
  while(pop > 0)
  {
    Person2List currentDV = personListArr[day];
    while(currentDV.root->next)
    {
      Person2* currentP = currentDV.root->next->me;
      for(int i = 0; i < currentP->numVisitors; i++)
      {
        Visitor v = currentP->visitors[i];
        Person2& p2 = people2[v.ID];
        if(p2.numVisitors > 0)
        {
          int mod = (day % v.period);
          int newdv = day + 3 + v.period * ((bool) mod) - mod;
          if(newdv < p2.dv)
          {
            p2.dv = newdv;
            personListArr[newdv].insert(&p2);
          }
        }
      }
      currentP->numVisitors = -1;
      currentDV.remove();
      pop--;
    }
    day++;
  }
  // Students write this.  Returns days until of last person catches the virus
  return day - 4; // to avoid warnings for now.
}
