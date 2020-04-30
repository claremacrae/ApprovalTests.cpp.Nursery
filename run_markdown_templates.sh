#!/usr/bin/env bash

dotnet tool update  -g MarkdownSnippets.Tool
mdsnippets || exit 1
