#ifndef BOINPUTMANAGER_H
#define BOINPUTMANAGER_H

class CBoInputManager {
public:
	void Update();
	void UpdateFE();
	void ResetState();
	bool AreLockedPlayersConnected();
};

#endif