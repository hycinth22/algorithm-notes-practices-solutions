id="$1"
title="$2$1"
folder="${title}"
complile="${folder}/$id.cpp ${folder}/fake_ostream.cpp"

mkdir "${folder}"
cp -r ../刷题模板/* "${folder}"/
mv "${folder}/main.cpp" "${folder}/$id.cpp"
echo "add_executable(${id} ${complile})" >> CMakeLists.txt
