#ifndef _HEALTHCARE_DEGENERATION_H_
#define _HEALTHCARE_DEGENERATION_H_

namespace healthcare {

class Degeneration {
 public:
  virtual int GetDegeneration(int age) const = 0;
  virtual ~Degeneration() {}
};

}  // namespace healthcare
#endif  // _HEALTHCARE_DEGENERATION_H_
