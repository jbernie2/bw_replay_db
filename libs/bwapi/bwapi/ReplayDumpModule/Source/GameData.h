#pragma once

#include "boost/archive/binary_oarchive.hpp"
#include "boost/archive/binary_iarchive.hpp"
#include "boost/serialization/map.hpp"
#include "boost/serialization/vector.hpp"
#include "boost/serialization/utility.hpp"

#include <BWAPI.h>
#include "Utils.h"

enum AttackType {
	DROP,
	GROUND,
	AIR,
	INVIS
};

struct Attack
{
	std::set<AttackType> types;
	int frame;
	int firstFrame;
	BWAPI::Position position;
	BWAPI::Position initPosition;
	double radius;
	// maximum number of units of each type "engaged" in the attack
	std::map<BWAPI::Player, std::map<BWAPI::UnitType, int> > unitTypes;
	std::map<BWAPI::Player, std::set<BWAPI::Unit> > battleUnits;
	std::map<BWAPI::Player, std::set<BWAPI::Unit> > workers;
	BWAPI::Player defender;
	double scoreGroundCDR;
	double scoreGroundRegion;
	double scoreAirCDR;
	double scoreAirRegion;
	double scoreDetectCDR;
	double scoreDetectRegion;
	double economicImportanceCDR;
	double economicImportanceRegion;
	double tacticalImportanceCDR;
	double tacticalImportanceRegion;
	
	Attack(const std::set<AttackType>& at, int f, BWAPI::Position p, double r, BWAPI::Player d,
		const std::map<BWAPI::Player, BWAPI::Unitset>& units);
	void addUnit(BWAPI::Unit u);
	void computeScores();
};

class GameData
{
public:
	GameData(); // Generates RLD file
	~GameData();
	void onFrame();
	void onReceiveText(BWAPI::Player player, std::string text);
	void onPlayerLeft(BWAPI::Player player);
	void onNukeDetect(BWAPI::Position target);
	void onUnitCreate(BWAPI::Unit unit);
	void onUnitDestroy(BWAPI::Unit unit);
	void onUnitMorph(BWAPI::Unit unit);
	void onUnitRenegade(BWAPI::Unit unit);

private:
	std::ofstream replayDat;
	std::list<Attack> attacks;
	std::map<BWAPI::Player, int> lastDropOrderByPlayer;
	
	std::map<BWAPI::Player, std::set<std::pair<BWAPI::Unit, BWAPI::UnitType> > > unseenUnits;

	std::map<BWAPI::Player, std::list<BWAPI::TechType> > listCurrentlyResearching;
	std::map<BWAPI::Player, std::list<BWAPI::TechType> > listResearched;
	std::map<BWAPI::Player, std::list<BWAPI::UpgradeType> > listCurrentlyUpgrading;
	std::map<BWAPI::Player, std::list<std::pair<BWAPI::UpgradeType, int> > > listUpgraded;


	void onUpdateAttacks();
	void onNewAttack(BWAPI::Unit unitKilled);
	std::map<BWAPI::Player, BWAPI::Unitset> getPlayerMilitaryUnitsNotInAttack(const BWAPI::Unitset& unitsAround);
	//void endAttack(std::list<Attack>::iterator it, BWAPI::Player loser, BWAPI::Player winner);

	void handleVisionEvents();
	void handleTechEvents();
	
};
