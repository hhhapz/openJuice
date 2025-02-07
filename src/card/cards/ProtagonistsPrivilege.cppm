module;

export module card.cards.ProtagonistsPrivilege;

import engine.card.CardTypes;

export class ProtagonistsPrivilege: public BoostCard {
private:
public:
    ProtagonistsPrivilege():
        BoostCard(1, true, "Protagonist's Privilege") {}
}