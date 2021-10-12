#!/usr/bin/env python3

from os import close, makedirs, path
from jinja2 import FileSystemLoader, Environment

className = input('Class name: ')

directory = input('Destination directory: ')

file_loader = FileSystemLoader('templates')

env = Environment(loader=file_loader)

headerTemplate = env.get_template('class.hpp.jinja2')
sourceTemplate = env.get_template('class.cpp.jinja2')

headerOutput = headerTemplate.render(className=className)
sourceOutput = sourceTemplate.render(className=className)

makedirs(directory, exist_ok=True)

headerFile = open(path.join(directory, className + '.hpp'), "w+")
sourceFile = open(path.join(directory, className + '.cpp'), "w+")

headerFile.write(headerOutput)
sourceFile.write(sourceOutput)
