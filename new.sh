id="$2"
title="$1$2"
folder="${title}"
complile="${folder}/$id.cpp"

mkdir "${folder}"
cp -r ../刷题模板/* "${folder}"/
mv "${folder}/main.cpp" "${folder}/$id.cpp"
echo "add_executable(${id} ${complile})" >> CMakeLists.txt
