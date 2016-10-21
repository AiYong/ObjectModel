#ifndef AMODIFIER_H
#define AMODIFIER_H

enum AModifier
{
    Public      = 1,
    Protected   = 2,
    Private     = 4,
    Final       = 8,
    Virtual     = 16,
    Override    = 32,
    NoExcept    = 64,
    Inline      = 128,
    Static      = 256,
    Const       = 512,
    Volatile    = 1024,
    Mutable     = 2048,
};

#endif // AMODIFIER_H
