#pragma once

#include "Resource.hpp"

class ResourceManager
{
public:
    Resource *obiekt;
    
    ResourceManager() {};
    ~ResourceManager() { delete this->obiekt; }

    ResourceManager(const ResourceManager& RM) { *(RM.obiekt) = Resource(); *(RM.obiekt) = *obiekt; }

    ResourceManager& operator=(const ResourceManager& R) { if (&R != this) { delete obiekt;  *(R.obiekt) = Resource(); *(R.obiekt) = *obiekt; return *this; } }

    ResourceManager(ResourceManager&& RP) { obiekt = RP.obiekt; RP.obiekt = nullptr; }

    double get() { return obiekt->get(); }
};
