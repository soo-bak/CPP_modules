#pragma once

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter {

  public:
    Character(void);
    Character(const std::string& name);
    Character(const Character& other);
    virtual ~Character(void);

    Character& operator = (const Character& other);

    virtual const std::string getName(void) const;
    virtual void equip(AMateria* materia);
    virtual void unequip(int index);
    virtual void use(int index, ICharacter& target);

    void setName(const std::string& newName);
    const int getInventoryCounts(void) const;
    void setInventoryCounts(const int& newInventoryCounts);
    AMateria* getInventory(const int& index) const;
    void setInventory(const int& index, const AMateria& newMateria);

  private:
    static const int _maxInventorySlot = 4;

    AMateria* _inventory[_maxInventorySlot];
    std::string _name;
    int _inventoryCounts;

};
