#ifndef __OBJECT_MANAGER_HPP__
#define __OBJECT_MANAGER_HPP__

#include "PersistentObject.hpp"
#include "../../Common/String.hpp"
#include "../../Common/List.hpp"
#include "../../Common/Iterator.hpp"
#include "../../Common/SmartPtr.hpp"

class ObjectManager
{
private:
	List objects;
	
public:
    ~ObjectManager();
	List& getAll() { return objects; } 
	int numberOfObjects();
	void remove(PersistentObject& po);
	void addObject(PersistentObject& po);
	void *operator[](int i) {return objects[i];}
	void deleteAll(); // Delete all instances to deallocate them from memory
};

#endif
