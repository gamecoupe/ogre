/*
-----------------------------------------------------------------------------
This source file is part of OGRE
    (Object-oriented Graphics Rendering Engine)
For the latest info, see http://www.ogre3d.org/

Copyright (c) 2000-2014 Torus Knot Software Ltd

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
-----------------------------------------------------------------------------
*/

#include "OgreGLSLESProgramFactory.h"
#include "OgreGLSLESProgramManager.h"
#include "OgreGLSLESProgram.h"
#include "OgreRoot.h"

namespace Ogre {
    GLSLESProgramManager* GLSLESProgramFactory::mProgramManager = NULL;
    //-----------------------------------------------------------------------
    String GLSLESProgramFactory::sLanguageName = "glsles";
    //-----------------------------------------------------------------------
    GLSLESProgramFactory::GLSLESProgramFactory(void)
    {
        if (mProgramManager == NULL)
        {
            mProgramManager = new GLSLESProgramManager();
        }
    }
    //-----------------------------------------------------------------------
    GLSLESProgramFactory::~GLSLESProgramFactory(void)
    {
        if (mProgramManager)
        {
            delete mProgramManager;
            mProgramManager = NULL;
        }
    }
    //-----------------------------------------------------------------------
    const String& GLSLESProgramFactory::getLanguage(void) const
    {
        return sLanguageName;
    }
    //-----------------------------------------------------------------------
    GpuProgram* GLSLESProgramFactory::create(ResourceManager* creator,
        const String& name, ResourceHandle handle,
        const String& group, bool isManual, ManualResourceLoader* loader)
    {
        return OGRE_NEW GLSLESProgram(creator, name, handle, group, isManual, loader);
    }
}
