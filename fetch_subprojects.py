#! /usr/bin/env python
"""
A script to generate a flat subproject directory from a tree of dependency directories
"""
import os
import subprocess

def dependency_directory():
  """
  A function isolating the path specification to the project's dependency directory
  """
  return os.path.join( os.getcwd(), "dependencies" )

def clone_submodule( relative_path ):
  """
  A function to clone a git submodule
  """
  print("")
  print("----------------------------------------")
  print("Fetching " + relative_path + "...")
  print("----------------------------------------")
  print("")
  invocation = [ "git", "submodule", "update", "-q", "--init", "--", relative_path ]
  if os.name == "nt":
    invocation.insert( 0, "powershell" )
  clone = subprocess.Popen( invocation )
  clone.communicate()

def update_repository():
  """
  A function to update a submodule to lastest commit of the master branch
  """
  print("Updating to master branch...")
  print("")
  invocation = ["git", "pull", "-q", "origin", "master"]
  if os.name == "nt":
    invocation.insert( 0, "powershell" )
  update = subprocess.Popen( invocation )
  update.communicate()
  
def traverse_dependencies( destination, traversed ):
  """
  Clone and update dependencies uniquely and collect links to dependency projects
  in a destination folder
  """
  if not os.path.isdir( dependency_directory() ):
    return
  os.chdir( dependency_directory() )

  for dependency in os.listdir(os.getcwd()) :
    if os.path.isdir( dependency ) and dependency not in traversed :
        traversed.add( dependency )
        clone_submodule( dependency )
        os.chdir( dependency )
        update_repository()
        if not os.path.isdir( os.path.join( destination, dependency ) ):
          os.symlink( os.getcwd(), os.path.join( destination, dependency ) )
        traverse_dependencies( destination, traversed )
        os.chdir( ".." )
  os.chdir( os.path.join( ".." ) )

def collect_subprojects():
  destination = os.path.join( os.getcwd(), "subprojects" )
  if not os.path.isdir( destination ):
    os.makedirs( destination )
  traverse_dependencies( destination, set() )

collect_subprojects()
