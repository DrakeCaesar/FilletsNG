#ifndef HEADER_MODELLIST_H
#define HEADER_MODELLIST_H

class View;

class Landslip;

#include "Cube.h"

#include <vector>
#include <SDL_render.h>

/**
 * Wrapper around list of models.
 */
class ModelList {
private:
    const Cube::t_models *m_models;

public:
    ModelList(const Cube::t_models *models);

    int size() const { return (int) m_models->size(); }

    void drawOn(View *view, SDL_Renderer *renderer) const;

    bool stoneOn(Landslip *slip) const;

    bool fallOn(Landslip *slip) const;
};

#endif
