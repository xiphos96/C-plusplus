#pragma once
#include <ds/List.h>

class Team;
class AddressSpace;

class TeamManager
{
public:
	/// Ŀ�� ���ýÿ� �ʱ�ȭ�� ���� ȣ���
	void Bootstrap();

	//���� �����Ѵ�.
	Team* CreateTeam(const char* name); 
	Team* CreateTeam(const char* name, AddressSpace* addressSpace);

	List& GetTeamList() { return m_teamList; }

	//���� ã�´�.
	Team* FindTeam(int teamId);

	static TeamManager* GetInstance()
	{
		if (m_pTeamManager == nullptr)
			m_pTeamManager = new TeamManager();

		return m_pTeamManager;
	}

	static void PrintThreads(int argc, const char** argv);
	static void PrintAreas(int argc, const char** argv);
	static void PrintTeamModules(int argc, const char** argv);
	static void PrintHandles(int argc, const char** argv);

	// Call a function for every team in the system
	static void DoForEach(void (*EachTeamFunc)(void*, Team*), void*);


private:
	TeamManager();
	static TeamManager* m_pTeamManager;

	int	m_teamId;
	List m_teamList;
};

