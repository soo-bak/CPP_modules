#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
    : _materiaCount(0) {
}

MateriaSource::MateriaSource(const MateriaSource& other)
    : _materiaCount(other.getMateriaCount()) {
  for (int i = 0; i < _maxLearnableNumber; i++) {
    setLearnedMateria(i, other.getLearnedMateria(i));
  }
}

MateriaSource::~MateriaSource(void) {
  for (int i = 0; i < _materiaCount; i++) {
    if (_learnedMateria[i] != NULL) {
      delete _learnedMateria[i];
    }
  }
}

MateriaSource& MateriaSource::operator = (const MateriaSource& other) {
  for (int i = 0; i < _maxLearnableNumber; i++) {
    setLearnedMateria(i, other.getLearnedMateria(i));
  }
  return *this;
}

void MateriaSource::learnMateria(AMateria* materia) {
  if (_materiaCount == _maxLearnableNumber) {
    return ;
  } else {
    _learnedMateria[_materiaCount] = materia;
    _materiaCount++;
  }
  return ;
}

AMateria* MateriaSource::createMateria(const std::string& type) {
  for (int i = 0; i < _materiaCount; i++) {
    if (_learnedMateria[i]->getType() == type) {
      return _learnedMateria[i];
    }
  }
  return 0;
}

AMateria* MateriaSource::getLearnedMateria(int index) const {
  return _learnedMateria[index];
}

void MateriaSource::setLearnedMateria(int index, const AMateria* const & newMateria) {
  if (_learnedMateria[index] != NULL) {
    delete _learnedMateria[index];
  }
  _learnedMateria[index] = newMateria->clone();
  return ;
}

int MateriaSource::getMateriaCount(void) const {
  return _materiaCount;
}

void MateriaSource::setMateriaCount(const int& newMateriaCount) {
  _materiaCount = newMateriaCount;
  return ;
}
