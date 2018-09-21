//
//  mono.c
//  OutlineViewTest
//
//  Created by Chris Hamons on 9/21/18.
//  Copyright © 2018 Felix Deimel. All rights reserved.
//

#include <mono/jit/jit.h>
#include <mono/metadata/assembly.h>
#include <mono/metadata/debug-helpers.h>
#include <mono/metadata/threads.h>

void Die (char * error)
{
    printf ("%s\n", error);
    exit (1);
}

void DoMono ()
{
    
    MonoDomain *domain = mono_jit_init ("Test");
    
    MonoAssembly *assembly = mono_domain_assembly_open (domain, "/Users/donblas/tmp/2nd/MonoOnMojave/foo.dll");
    if (!assembly)
        Die ("Unable to load library");
    
    MonoImage *image = mono_assembly_get_image (assembly);
    MonoClass *my_class = mono_class_from_name (image, "Test", "Foo");
    if (!assembly)
        Die ("Unable to find class");
    
    MonoObject *my_class_instance = mono_object_new (domain, my_class);
    mono_runtime_object_init (my_class_instance);
    
    mono_thread_attach (mono_get_root_domain ());
    
}
