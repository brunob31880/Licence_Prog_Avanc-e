
#include "maze.h"
#include <iostream>
using namespace maze;
using namespace mazeNode;
using namespace std;

Maze::Maze(const char ascii[16][16], startPoint point)
{
   // créer les noeuds en fonction du caractère
   for (int i = 0; i < 16; i++)
   {
      for (int j = 0; j < 16; j++)
      {
         if (ascii[i][j] == 'w')
            this->nodes[i][j] = new mazeNode::NodeWall();
         else if (ascii[i][j] == ' ')
            this->nodes[i][j] = new mazeNode::NodeFree();
         else if (ascii[i][j] == 'c')
            this->nodes[i][j] = new mazeNode::NodeCheese();
      }
   }
   // créer les liens entres voisins
   for (int i = 0; i < 16; i++)
   {
      for (int j = 0; j < 16; j++)
      {
         if (i > 0)
            this->nodes[i][j]->setNeighbor(mazeNode::NodeNeighbor_Up, this->nodes[i - 1][j]);
         else
            this->nodes[i][j]->setNeighbor(mazeNode::NodeNeighbor_Up, NULL);
         if (i < 15)
            this->nodes[i][j]->setNeighbor(mazeNode::NodeNeighbor_Down, this->nodes[i + 1][j]);
         else
            this->nodes[i][j]->setNeighbor(mazeNode::NodeNeighbor_Down, NULL);
         if (j > 0)
            this->nodes[i][j]->setNeighbor(mazeNode::NodeNeighbor_Left, this->nodes[i][j - 1]);
         else
            this->nodes[i][j]->setNeighbor(mazeNode::NodeNeighbor_Left, NULL);
         if (j < 15)
            this->nodes[i][j]->setNeighbor(mazeNode::NodeNeighbor_Right, this->nodes[i][j + 1]);
         else
            this->nodes[i][j]->setNeighbor(mazeNode::NodeNeighbor_Right, NULL);
      }
   }
   if (point.line < 0 || point.line > 15 || point.col < 0 || point.col > 15)
   {
      cout << "!!! Warning initialisation maze coordonnées starter !!!" << endl;
      this->starter = NULL;
   }
   else if (this->nodes[point.line][point.col]->getType() != NodeType_Free)
   {
      cout << "!!! Warning initialisation maze coordonnées starter case occupée!!!" << endl;
      this->starter = NULL;
   }
   else
   {
      // point de départ
      this->nodes[point.line][point.col]->setVisited();
      this->starter = this->nodes[point.line][point.col];
   }
}

Maze::~Maze()
{
   // peut-être des choses à supprimer
}

bool Maze::checkConsistency()
{
   bool cheeseFind = false;
   // tous les noeuds sont instanciés
   for (int i = 0; i < 16; i++)
   {
      for (int j = 0; j < 16; j++)
      {
         // Si le noeud a un type eNodeType   NodeType_Wall ou NodeType_Free ou NodeType_Cheese tout va bien par contre le contraire...
         if ((this->nodes[i][j]->getType() != mazeNode::NodeType_Wall) && (this->nodes[i][j]->getType() != mazeNode::NodeType_Free) && (this->nodes[i][j]->getType() != mazeNode::NodeType_Cheese))
            return false;
         else if (this->nodes[i][j]->getType() == mazeNode::NodeType_Cheese)
            cheeseFind = true;
      }
   }
   // presence d'un fromage
   if (cheeseFind == false)
      return false;

   // point de départ valide
   if (this->starter == NULL)
      return false;

   return true;
}

bool Maze::solve()
{
   return this->parse(this->starter);
}

void Maze::getAsciiFormat(char ascii[16][16])
{
   for (int i = 0; i < 16; i++)
   {
      for (int j = 0; j < 16; j++)
      {
         ascii[i][j] = this->nodes[i][j]->getString();
      }
   }
}

bool Maze::parse(mazeNode::Node *node)
{
   // la récursivité peut-être intéressante pour le parcours d'un arbre de noeuds
   // On va examiner tous les voisins du noeud
   bool ret = false;
   for (int i = NodeNeighbor_Up; i <= NodeNeighbor_Right; i++)
   {
      eNodeNeighbor neighbor = static_cast<eNodeNeighbor>(i);

      if (node->isNeighborFree(neighbor))
      {
         std::cout << "Node " << node->getString() << " has neighbour free dir " << neighbor << std::endl;
         char ascii[16][16];
         this->getAsciiFormat(ascii);
         for (int line = 0; line < 16; line++)
         {
            for (int col = 0; col < 16; col++)
            {
               std::cout << ascii[line][col] << " ";
            }
            std::cout << std::endl;
         }
         // s'il est free on le visite ce qui permet de garder une trace de notre passage
         //  ce qui permet aussi d'eviter un bouclage infini
         node->getNeighbor(neighbor)->setVisited();
         // si c'est le fromage c'est terminé
         if (node->getNeighbor(neighbor)->getType() == mazeNode::NodeType_Cheese)
            return true;
         else
            // sinon on rappel parse recursivement sur le voisin
            ret |= this->parse(node->getNeighbor(neighbor));
      }
   }
   return ret;
}
