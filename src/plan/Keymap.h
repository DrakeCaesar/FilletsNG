#ifndef HEADER_KEYMAP_H
#define HEADER_KEYMAP_H

#include "KeyDesc.h"
#include "KeyStroke.h"

#include "SDL2/SDL.h"
#include <map>
#include <string>

/**
 * Table of defined keys.
 */
class Keymap
{
private:
  typedef std::map<KeyStroke, KeyDesc, stroke_less> t_keys;
  t_keys m_keys;

public:
  void registerKey(const KeyStroke &stroke, const KeyDesc &desc);

  int indexPressed(const KeyStroke &stroke) const;
};

#endif
