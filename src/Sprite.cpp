#include "Sprite.h"

Sprite::Sprite()
{
    _vboID = 0;
}

Sprite::~Sprite()
{
    if(_vboID != 0)
    {
        glGenBuffers(1, &_vboID);
    }
}

void Sprite::init(float x, float y, float height, float width)
{
    _x = x;
    _y = y;
    _height = height;
    _width = width;

    if(_vboID == 0)
    {
        glGenBuffers(1, &_vboID);
    }

    float vertexData[12];
    int i = 0;

    //First triangle
    vertexData[i] = x;
    i++;
    vertexData[i] = y;
    i++;
    vertexData[i] = x + width;
    i++;
    vertexData[i] = y;
    i++;
    vertexData[i] = x;
    i++;
    vertexData[i] = y - height;
    i++;
    //Secound triangle
    vertexData[i] = x;
    i++;
    vertexData[i] = y - height;
    i++;
    vertexData[i] = x + width;
    i++;
    vertexData[i] = y - height;
    i++;
    vertexData[i] = x + width;
    i++;
    vertexData[i] = y;

    glBindBuffer(GL_ARRAY_BUFFER, _vboID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Sprite::draw()
{
    glBindBuffer(GL_ARRAY_BUFFER, _vboID);

    glEnableVertexAttribArray(0);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

    glDrawArrays(GL_TRIANGLES, 0, 6);

    glDisableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
}