#include "Character.hpp"

Character::Character(void)
    : _name("unknown"), _inventoryCounts(0) {
}

Character::Character(const std::string& nameInput)
    : _name(nameInput), _inventoryCounts(0) {
}

Character::Character(const Character& other)
    :_name(other.getName()),
     _inventoryCounts(other.getInventoryCounts()) {
  for (int i = 0; i < _maxInventorySlot; i++) {
    setInventory(i, *other.getInventory(i));
  }
}

Character::~Character(void) {
  for (int i = 0; i < _maxInventorySlot; i++) {
    if (_inventory[i] != NULL) {
      delete _inventory[i];
    }
  }
}

Character& Character::operator = (const Character& other) {
  setName(other.getName());
  setInventoryCounts(other.getInventoryCounts());
  for (int i = 0; i < _maxInventorySlot; i++) {
    setInventory(i, *other.getInventory(i));
  }
}

void Character::equip(AMateria* materia) {
  if (_inventoryCounts == _maxInventorySlot) {
    return ;
  } else {
    setInventory(_inventoryCounts, *materia);
    _inventoryCounts++;
  }
  return ;
}

void Character::unequip(int index) {
  if (index >= _maxInventorySlot || index < 0) {
    return ;
  } else if (_inventory[index] == NULL) {
    return ;
  } else {
    _inventory[index] = NULL;
    for (int i = 0; i < _maxInventorySlot; i++) {
      if ((_inventory[i] == NULL) && _inventory[i + 1] != NULL) {
        _inventory[i] = _inventory[i + 1];
        _inventory[i + 1] = NULL;
      }
    }
  }
  return ;
}

void Character::use(int index, ICharacter& target) {
  getInventory(index)->use(target);
  return ;
}

void Character::setName(const std::string& newName) {
  _name = newName;
  return ;
}

const int Character::getInventoryCounts(void) const {
  return _inventoryCounts;
}

void Character::setInventoryCounts(const int& newInventoryCount) {
  _inventoryCounts = newInventoryCount;
  return ;
}

AMateria* Character::getInventory(const int& index) const {
  return _inventory[index];
}

void Character::setInventory(const int& index, const AMateria& newMateria) {
  if (_inventory[index] != NULL) {
    delete _inventory[index];
  }
  _inventory[index] = newMateria.clone();
  return ;
}
