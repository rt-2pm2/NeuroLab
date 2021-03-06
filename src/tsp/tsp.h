#ifndef TSP_H
#define TSP_H

#include <QGraphicsScene>
#include <QGraphicsItem>

#include <chrono>
#include <vector>

#include "optimizationproblem.h"

typedef std::pair<int, int> Coordinate;

class TSP : public QGraphicsScene, public GAOptimizationProblem<int>
{
    Q_OBJECT

    std::vector<QGraphicsItem *> targets;
    std::vector<QGraphicsItem *> steps;

  public:
    TSP(QObject *parent = Q_NULLPTR);
    std::vector<Coordinate> getTargets();
    void setPath(const std::vector<Coordinate> &steps);
    unsigned int getSolutionSize() const;
    double evaluateSolution(const std::vector<int> &s) const;
    void showSolution(const std::vector<int> &s);
    std::vector<int> crossover(const std::vector<int> &a, const std::vector<int> &b);
    void mutate(std::vector<int> &);
    std::vector<int> getRandomSolution() const;
    void generateRandom(unsigned int);
    void addProblemElement(int x, int y);
    void removeProblemElement(int x, int y);
    void clear();

  public slots:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
};

#endif // TSP_H
