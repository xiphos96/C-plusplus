#ifndef __LEVEL_H__
#define __LEVEL_H__

#include <iostream>
#include <vector>
#include "Layer.h"
#include "LevelParser.h"
#include "Player.h"
#include "CollisionManager.h"
#include "PathManager.h"
#include "TriggerGenerator.h"

class TileLayer;
class GameObject;
class Level;
class Player;
class Explosion;
class PathPlanner;

struct Tileset
{
    int firstGridID;
    int tileWidth;
    int tileHeight;
    int spacing;
    int margin;
    int width;
    int height;
    int numColumns;
    std::string name;

	Tileset(){
		firstGridID = 0;
		tileWidth = 0;
		tileHeight = 0;
		spacing = 0;
		margin = 0;
		width = 0;
		height = 0;
		numColumns = 0;
	}
};

class Level
{
public:
	Level(int width, int height);
	~Level();
    
	void Update();
    void Render();
    
    std::vector<Tileset>* getTilesets() { return &m_tilesets; }
    std::vector<Layer*>* getLayers() { return &m_layers; }    
    std::vector<TileLayer*>* getCollisionLayers() { return &m_collisionLayers; }

//����, ��Ʈ��ũ �÷��̾ �߰��ϰų� �����Ѵ�.
	bool AddPlayers(Player* pPlayer);
	bool RemovePlayers(Player* pPlayer);
	std::vector<Player*>& GetPlayers(){ return m_players; }
	
//���̵�� ���� ���� ������Ʈ�� ����.
	GameObject* GetGameObjectFromID(int id);

//�÷��̾ ������Ʈ�Ѵ�.
	void UpdatePlayers();

//���� ������Ʈ�� ������Ʈ�Ѵ�.
	void UpdateObject();

//�׺���̼� �׷����� �����Ѵ�.
	void GenerateNavigationGraph();

//�׺���̼� �׷����� ��带 �߰��Ѵ�. ������ ���� ���� �̾��� ��� ȣ��ȴ�.
	bool AddNavigationNode(int x, int y);

//�׺���̼� �׷������� ��带 �����Ѵ�. ���� �������� ����
	bool RemoveNavigationNode(int x, int y){ return false; }

	std::vector<GameObject*>* getGameObjects() { return &m_gameObjects; }

	bool AddGameObject(GameObject* pObject);
	bool AddReserveObject(GameObject* pObject);

//�ش� Ÿ�Ͽ� �������� �����ϴ� ������ ����
	void GenerateItem(int tileRow, int tileColumn);

//������ Ʈ���Ÿ� �߰��Ѵ�.
	void AddTrigger(int x, int y, std::string& triggerType);

//Ʈ���� �ý���
	TriggerSystem<Trigger<GameObject>>* GetTriggerSystem(){ return &m_TriggerSystem; }
	
//�н� �Ŵ���
	PathManager<PathPlanner>* const    GetPathManager(){ return m_pPathManager; }	

//�÷��̾�� ���� ������Ʈ���� �浹�� üũ�ϰ� �� ���ӿ�����Ʈ ������ ���� ó���� �����Ѵ�.
	void CheckPlayerCollision();

//�ش� ���� ������Ʈ�� ��ġ�� �־��� ������ ������ ����Ų��.
	void CreateExplosion(GameObject* pGameObject, int bombPower, int bombType);

//��ź ���߽� ������ �ִ� ������ �� ������ ������ �浹�� üũ
	bool CheckExplosionEffect(Explosion* pExplosion);

	GameMap* const GetMap(){ return m_pMap; }

//���� �ȵ�� �޼ҵ�
	Vector2D GetRandomItemPos(int iItemToGet);
	Vector2D GetCloseWallPos(Vector2D& source);
	
	bool isPathObstructed(Vector2D A, Vector2D B, double    BoundingRadius)const;
	
	Vector2D GetRandomSpawnPoint(){ return m_SpawnPoints[RandInt(0, m_SpawnPoints.size() - 1)]; }
	
private:
	std::vector<Player*> m_players;
    
    std::vector<Layer*> m_layers;
    std::vector<Tileset> m_tilesets;
    std::vector<TileLayer*> m_collisionLayers;

	std::vector<GameObject*> m_gameObjects;
	std::vector<GameObject*> m_reserveAddObjects;

	int m_mapWidth;
	int m_mapHeight;

	TriggerSystem<Trigger<GameObject>> m_TriggerSystem;
	TriggerGenerator m_TriggerGenerator;

	std::vector<Vector2D>  m_SpawnPoints;
	PathManager<PathPlanner>*  m_pPathManager;
	GameMap*  m_pMap;
};

#endif 
