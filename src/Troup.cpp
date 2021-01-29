#include "Troup.h"

#include "Grid.h"

GridCase* Troup::canAttack(Grid* grid, int casePosition, int moveDirection) {
    GridCase* target = nullptr;

    // tempo : no range finding :
    if (!grid->find(casePosition + moveDirection)->isEmpty() && _owner != grid->find(casePosition + moveDirection)->getUnit()->getOwner())
        target = grid->find(casePosition + moveDirection);
    else if (grid->find(casePosition + moveDirection)->getPosition() == 0 || grid->find(casePosition + moveDirection)->getPosition() == grid->getGridSize()-1)  // is a base
        target = grid->find(casePosition + moveDirection);

    // TODO : handle owner's troup can be included in target in case of Catapult
    // for(std::vector<int> vec : _reach) {
    //     for(int pos : vec) {
    //         if(!grid->find(casePosition + moveDirection*pos)->isEmpty())
    //             return grid->find(casePosition + moveDirection*pos);
    //     }
    // }

    // TODO : handle unit range
    // TODO : handle base in front

    return target;
}

std::string Troup::attack(Grid* grid, GridCase* target) {
    std::string description = "";

    // TODO : handle "multiple victims" if this==Catapult (/!\ border limits)
    // TODO : handle "soldier promotion"

    // target name is comptuted before in case of target death later ("NPE" risk)
    std::string targetName = (target->getPosition() == 0 || target->getPosition() == grid->getGridSize()-1) // is a base
                                ? target->isEmpty()
                                    ? "base"
                                    : target->getTroupName()
                                : target->getTroupName();

    bool targetIsDead = target->isEmpty()
                        ? ((HomeCase*)target)->suffersAttack(_damage)
                        : target->suffersAttack(_damage);

    std::string attackResult = targetIsDead // is a base
                             ? " kills "
                             : " attacks ";

    description += "\tUnit " + this->getName() + attackResult + "opponent's " + targetName + " !" + "\n";

    return description;
}
