#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include <vector>
#include "BomberManStructure.h"
#include "PlatformerObject.h"
#include "GameObjectFactory.h"
#include "PathPlanner.h"
#include "SteeringBehaviors.h"

class Goal_Think;
class Level;
class Regulator;

class Player : public PlatformerObject
{
public:
    
    Player(Level* pLevel);
	virtual ~Player();
    
	virtual void Load(LoaderParams& params);
    
    virtual void Draw();
	virtual void Update();
    virtual void Clean();
    
    virtual void Collision();
    
    virtual std::string type() { return "Player"; }

//�ִϸ��̼� ó���� ���� �ӽ� ���� ����ü
//Deprecated
	LoaderParams* m_liveParam;
	LoaderParams* m_dieParam;

    // bring the player back if there are lives left
    void ressurect();

	bool CheckCollision(std::vector<GameObject*>& gameObject);
    
// ���̽�ƽ, ���콺, Ű����, ��ġ �̺�Ʈ�� �ٷ��.
    void HandleInput();
    
    bool handleMovement();

//�÷��̾��� �ִϸ��̼� ó��. SDL, Cocos2d-x ��뿡 ���� �ش� �ڵ�� ����Ǿ�� �Ѵ�.
	void HandleAnimation();

//AI ó���� ���� �޼ҵ�
	PathPlanner* const GetPathPlanner(){ return m_pPathPlanner; }
	Steering* const GetSteering(){ return m_pSteering; }
	Goal_Think* const GetBrain(){ return m_pBrain; }
	bool isPossessed()const{ return m_bPossessed; }
	void SetPossessed(bool bPossessed) { m_bPossessed = bPossessed; }

//������ ����� ��� AI�� ��ü�� �����ϵ��� �Ѵ�.
//���� ���̵� ���� ���߽� �߿��� ������ �� ���̴�.
	void Exorcise();

//�÷��̾ �ش� ��ġ�� �ִ����� üũ.	��Ȳ�� ���� ���� ������ �� �ʿ䰡 �ִµ�
//����� ������ 0�� �����ߴ�.
	bool IsAtPosition(Vector2D pos);

//���� ������ �ӵ��� �̵��� �� �������� �����ϴ� �ð��� ���Ѵ�. 
//FrameRate ������ 60���� �����ߴµ� ���� �����ؾ� �Ѵ�.
	double CalculateTimeToReachPosition(Vector2D pos);

//�뺸���� �޽����� ó���Ѵ�.
	bool HandleMessage(const Telegram& msg);

//���� ������ ���õ� �޼ҵ�
	bool IsMyBomb(GameObject* pGameObject);
	bool InstallBomb();

//��ź Ÿ���� �����Ѵ�.
	void SetBombType(int bombType){ m_playerStat.bombType = bombType; }
	void IncreaseBombCount(){ m_playerStat.maxBombCount++;}
	void IncreaseBombPower(){ m_playerStat.bombPower++; }

	PlayerStatInfo& GetPlayerStat(){ return m_playerStat; }

	bool IsOverlappedWithBomb(){return m_bObjectOverlapped;}
	void SetOverlappedWithBomb(bool bOverlapped){ m_bObjectOverlapped = bOverlapped; }

private:
	int m_frameAnchorIndex;
	bool m_bPressedSpace;

//������ ���� ������ ���������� ����� ������
	std::vector<int> m_installedBomb;
//��ź ��ġ�� �÷��̾�� ��ź�� ��ġ�µ� �� ��� �÷��̾ ������ �� �־�� �Ѵ�.
//���� ������ ������ �ӽ÷� �ϴ� ó��
	bool m_bObjectOverlapped;	
	
//�÷��̾� ����
	PlayerStatInfo m_playerStat;

//�÷��̾ ��õ��� �������¿� �ְ� �Ѵ�. �����������ÿ� �ʿ�
    int m_bInvulnerable;
    int m_invulnerableTime;
    int m_invulnerableCounter;

//�÷��̾� AI
	//�� �÷��װ� ������ �Ǹ� ������ �÷��̾ �����Ѵ�. �׷��� ������ AI�� �÷��̾ �����Ѵ�.
	bool m_bPossessed;
	//�̵� ��θ� ��ȹ�ϱ� ���� ��� ��ȹ��. PathManager�� ����Ͽ� �Ź� ������Ʈ ���� �ʰ� PathManager�� ������Ʈ�� �����ϵ��� �ؼ� CPU ���ϸ� ���δ�.
	PathPlanner* m_pPathPlanner;
	//AI�� �����ϱ� ���� ��ü. ��Ȳ�� ���� �˰����� ����Ѵ�(��ȸ, �̵�, ����, ȸ�� ���)
	Steering* m_pSteering;
	//AI�� ������ �����Ͽ� ��Ȳ�� ���� ������ �����ϰ� �ش� ������ �����Ѵ�.
	Goal_Think* m_pBrain;

	//��ǥ �Ǵ�
	Regulator*  m_pGoalArbitrationRegulator;
};

#endif
