#include "Object_Pattern1.h"
#include "BulletSpawn.h"

Object_Pattern1::Object_Pattern1()
{
	components.push_back(new BulletSpawn());
	position = Vector(300, 300);
	spawnPos.resize(4);
	spawnPos[0] = Vector(300, 200);
	spawnPos[1] = Vector(200, 300);
	spawnPos[2] = Vector(300, 400);
	spawnPos[3] = Vector(400, 300);
}


Object_Pattern1::~Object_Pattern1()
{
}

void Object_Pattern1::step()
{
	static int t = 0;
	if (t % 5 == 0)
	{
		//int c = (t/3) % 4;
		for (int c = 0; c < 4; c++)
		{
			float a = sin((float)t / 20);
			float b = cos((float)t / 20);
			getComponent<BulletSpawn>()->spawn(spawnPos[c], Vector(a, b), Vector(a/50, b/50));
			getComponent<BulletSpawn>()->spawn(spawnPos[c], Vector(-b, a), Vector(-b/50, a/50));
			getComponent<BulletSpawn>()->spawn(spawnPos[c], Vector(-a, -b), Vector(-a/50, -b/50));
			getComponent<BulletSpawn>()->spawn(spawnPos[c], Vector(b, -a), Vector(b/50, -a/50));
			spawnPos[c] += Vector(2 * sin((float)t / 200), 2 * cos((float)t / 200));
		}
	}
	
	t++;
}