#!/bin/bash

echo "Started the ReadMe Generation"

python "readme Generation.py"

echo "Readme Generated for main folder"

cd "code monk"

python "readme Generation.py"

cd ../CodeChef

echo "Readme Generated for code monk folder"

python "readme Generation.py"

cd ../CodeForces

echo "Readme Generated for CodeChef folder"

python "readme Generation.py"

cd "../Geek for Geek"

echo "Readme Generated for CodeForces folder"

python "readme Generation.py"

cd "../hackerearth"

echo "Readme Generated for Geek for Geek folder"

python "readme Generation.py"

cd "../hackerrank"

echo "Readme Generated for hackerearth folder"

python "readme Generation.py"

echo "Readme Generated for hackerrank folder"

cd "../Hiring"

python "readme Generation.py"

echo "Readme Generated for Hiring folder"

cd "../leet code"

python "readme Generation.py"

echo "Readme Generated for leet code folder"

cd "../Rated competition Codes"

python "readme Generation.py"

echo "Readme Generated for Rated competition Codes folder"

cd ..

echo "Done with Readme Generation"