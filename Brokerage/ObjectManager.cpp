#include "ObjectManager.hpp"

ObjectManager::~ObjectManager()
{
}

void ObjectManager::deleteAll()
{
	for (SmartPtr<Iterator> it(objects.getIterator()); it->hasNext(); )
	{
		PersistentObject *po = (PersistentObject *) it->next();
		if (po)
			delete po, po = 0;
	}
	
}

int ObjectManager::numberOfObjects()
{
	return objects.count();
}

void ObjectManager::remove(PersistentObject& po)
{
    objects.remove(&po);
}

void ObjectManager::addObject(PersistentObject& po)
{
	objects.append(&po);
}
