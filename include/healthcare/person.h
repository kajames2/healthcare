#ifndef _HEALTHCARE_PERSON_H_
#define _HEALTHCARE_PERSON_H_

#include "healthcare/consumption.h"
#include "healthcare/degeneration.h"
#include "healthcare/job.h"
#include "healthcare/regeneration.h"

namespace healthcare {
class Person {
 public:
  Person();
  Person(int a, int h, int c);

  virtual void Work(const Job* job);
  void RegainHealth(const Regeneration* regen);
  void Degenerate(const Degeneration* degen);
  void AdvanceInAge();
  void Consume(const Consumption* consume);

  void SetHealthSpending(int health_spending) {
    health_spending_ = health_spending;
  }
  void SetEnjoymentSpending(int joy_spending) { joy_spending_ = joy_spending; }
  bool IsAlive() const { return !is_dead_; }
  bool IsDead() const { return is_dead_; }
  int GetAge() const { return age_; }
  int GetHealth() const { return health_; }
  int GetCash() const { return cash_; }
  double GetLifeEnjoyment() const { return life_enjoyment_; }

 protected:
  void GainHealth(int health_gain);
  void LoseHealth(int health_lose);
  int age_;
  int health_;
  int cash_;

 private:
  bool is_dead_;
  int joy_spending_;
  int health_spending_;
  int life_enjoyment_;
};

}  // namespace healthcare
#endif  // _HEALTHCARE_PERSON_H_
