#!/bin/bash

# Navigate to your project directory if the script is not in it
# cd /path/to/your/project

# Staging changes
git add .

# Committing changes. You can customize the commit message.
read -p "Enter commit message: " commitMessage
git commit -m "$commitMessage"

# Pushing changes
gitBranch=$(git symbolic-ref --short HEAD)
git push -u origin $gitBranch

echo "Changes pushed to $gitBranch"
