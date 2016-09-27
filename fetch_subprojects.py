#! /usr/bin/env python
"""
A script to generate a flat subproject directory from a tree of dependency directories
"""
import os

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
  invocation = [ "git", "submodule", "update", "--init", "--", relative_path ]
  if os.name == "nt":
    invocation.insert( 0, "powershell" )
  subprocess.call( invocation )

def update_repository():
  """
  A function to update a submodule to lastest commit of the master branch
  """
  print("Updating to master branch...")
  print("")
  invocation = ["git", "pull", "origin", "master"]
  if os.name == "nt":
    invocation.insert( 0, "powershell" )
  subprocess.call( invocation )
  
def traverse_dependencies( destination, traversed ):
  """
  Clone and update dependencies uniquely and collect links to dependency projects
  in a destination folder
  """
  if not os.isdir( dependency_directory() ):
    os.chdir( ".." )
    return
  os.chdir( dependency_directory() )
  for dependency in os.listdir() :
    if os.path.isdir( dependency ) and not dependency in traversed :
        traversed.add( dependency )
        clone_submodule( dependency )
        os.chdir( dependency )
        update_repository()
        os.symlink( os.getcwd(), os.path.join( destination, dependency ) )
        traverse_dependencies( destination, traversed )
        os.chdir( ".." )

def collect_subprojects():
  destination = os.path.join( os.getcwd(), "subprojects" )
  if not os.path.isdir( destination ):
    os.makedirs( directory )
  traverse_dependencies( destination, set() )

collect_subprojects()
