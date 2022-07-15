#include <iostream>
#include <string>

/*
 * Example of `bridge' design pattern
 * Copyright (C) 2011 Radek Pazdera
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <string>

namespace bridge {

/* Implemented interface. */
class AbstractInterface
{
    public:
        virtual void someFunctionality() = 0;
};

/* Interface for internal implementation that Bridge uses. */
class ImplementationInterface
{
    public:
        virtual void anotherFunctionality() = 0;
};

/* The Bridge */ 
class Bridge : public AbstractInterface
{
    protected:
        ImplementationInterface* implementation;
    
    public:
        Bridge(ImplementationInterface* backend)
        {
            implementation = backend;
        }
};

/* Different special cases of the interface. */

class UseCase1 : public Bridge
{
    public:
        UseCase1(ImplementationInterface* backend)
          : Bridge(backend)
        {}

        void someFunctionality()
        {
            std::cout << "UseCase1 on ";
            implementation->anotherFunctionality();
        }
};

class UseCase2 : public Bridge
{
    public:
        UseCase2(ImplementationInterface* backend)
          : Bridge(backend)
        {}

        void someFunctionality()
        {
            std::cout << "UseCase2 on ";
            implementation->anotherFunctionality();
        }
};

/* Different background implementations. */

class ConcreteImplementation1 : public ImplementationInterface
{
    public:
        void anotherFunctionality()
        {
            std::cout << "ConcreteImplementation1 :-!" << std::endl;
        }
};

class ConcreteImplementation2 : public ImplementationInterface
{
    public:
        void anotherFunctionality()
        {
            std::cout << "ConcreteImplementation2! :-)" << std::endl;
        }
};

} /* namespace bridge */

int main(int argc, char *argv[])
{
    using namespace bridge;

    AbstractInterface *useCase = 0;
    ImplementationInterface *osConcreteImplementation1 = new ConcreteImplementation1;
    ImplementationInterface *osConcreteImplementation2 = new ConcreteImplementation2;


    /* First case */
    useCase = new UseCase1(osConcreteImplementation1);
    useCase->someFunctionality();

    useCase = new UseCase1(osConcreteImplementation2);
    useCase->someFunctionality();

    /* Second case */
    useCase = new UseCase2(osConcreteImplementation1);
    useCase->someFunctionality();

    useCase = new UseCase2(osConcreteImplementation2);
    useCase->someFunctionality();


    return 0;
}
