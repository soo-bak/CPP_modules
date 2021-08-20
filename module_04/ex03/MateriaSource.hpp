#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {

  public:

    MateriaSource(void);
    MateriaSource(const MateriaSource& other);
    virtual ~MateriaSource(void);

    MateriaSource& operator = (const MateriaSource& other);

    virtual void learnMateria(AMateria* materia);
    virtual AMateria* createMateria(const std::string& type);

    AMateria* getLearnedMateria(int index) const;
    void setLearnedMateria(int index, const AMateria& newMateria);
    const int getMateriaCount(void) const;
    void setMateriaCount(const int& newMateriaCount);

  private:

    static const int _maxLearnableNumber = 4;

    AMateria* _learnedMateria[_maxLearnableNumber];
    int _materiaCount;
};
