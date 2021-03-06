#ifndef OPENMW_LOCALPLAYER_HPP
#define OPENMW_LOCALPLAYER_HPP

#include <components/openmw-mp/Base/BasePlayer.hpp>
#include "../mwworld/ptr.hpp"
#include <RakNetTypes.h>

namespace mwmp
{
    class Networking;
    class LocalPlayer : public BasePlayer
    {
    public:

        LocalPlayer();
        virtual ~LocalPlayer();

        void update();

        bool processCharGen();
        bool hasFinishedCharGen();

        void updateStatsDynamic(bool forceUpdate = false);
        void updateAttributes(bool forceUpdate = false);
        void updateSkills(bool forceUpdate = false);
        void updateLevel(bool forceUpdate = false);
        void updateBounty(bool forceUpdate = false);
        void updateReputation(bool forceUpdate = false);
        void updatePosition(bool forceUpdate = false);
        void updateCell(bool forceUpdate = false);
        void updateEquipment(bool forceUpdate = false);
        void updateInventory(bool forceUpdate = false);
        void updateAttack();
        void updateDeadState(bool forceUpdate = false);
        void updateAnimFlags(bool forceUpdate = false);

        void addItem(const Item &item);
        void addSpells();
        void addJournalItems();
        void addTopics();

        void removeItem(const Item &item);
        void removeSpells();

        void resurrect();

        void closeInventoryWindows();

        void setCharacter();
        void setDynamicStats();
        void setAttributes();
        void setSkills();
        void setLevel();
        void setBounty();
        void setReputation();
        void setPosition();
        void setMomentum();
        void setCell();
        void setClass();
        void setEquipment();
        void setInventory();
        void setSpellbook();
        void setQuickKeys();
        void setFactions();
        void setKills();
        void setBooks();
        void setShapeshift();
        void setMarkLocation();
        void setSelectedSpell();

        void sendClass();
        void sendInventory();
        void sendSpellbook();
        void sendCellStates();
        void sendSpellAddition(std::string id);
        void sendSpellAddition(const ESM::Spell& spell);
        void sendSpellRemoval(std::string id);
        void sendSpellRemoval(const ESM::Spell& spell);
        void sendQuickKey(unsigned short slot, QuickKey::Type type, const std::string& itemId = "");
        void sendJournalEntry(const std::string& quest, int index, const MWWorld::Ptr& actor);
        void sendJournalIndex(const std::string& quest, int index);
        void sendFactionRank(const std::string& factionId, int rank);
        void sendFactionExpulsionState(const std::string& factionId, bool isExpelled);
        void sendFactionReputation(const std::string& factionId, int reputation);
        void sendTopic(const std::string& topic);
        void sendKill(const std::string& refId, int number);
        void sendBook(const std::string& bookId);
        void sendScale(float newScale);
        void sendWerewolfState(bool isWerewolf);
        void sendMarkLocation(const ESM::Cell& newMarkCell, const ESM::Position& newMarkPosition);
        void sendSelectedSpell(const std::string& newSelectedSpellId);

        void clearCellStates();
        void clearCurrentContainer();

        void storeCellState(const ESM::Cell& cell, mwmp::CellState::Type stateType);
        void storeCurrentContainer(const MWWorld::Ptr& container);

        void playAnimation();
        void playSpeech();

        MWWorld::Ptr getPlayerPtr();

    private:
        Networking *getNetworking();

    };
}

#endif //OPENMW_LOCALPLAYER_HPP
