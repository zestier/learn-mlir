import argparse, os, re, shutil

def allowed_name(name):
    name = name.lower()
    if re.match(r"^[a-z][a-z0-9]*$", name):
        return name
    else:
        raise ValueError(str)

def readable_dir_path(filePath):
    if os.path.isdir(filePath):
        return filePath
    else:
        raise NotADirectoryError(filePath)

def writable_dir_path(filePath):
    if os.path.isdir(filePath):
        return filePath
    elif os.access(os.path.dirname(filePath), os.W_OK):
        return filePath
    else:
        raise NotADirectoryError(filePath)

parser = argparse.ArgumentParser()
parser._action_groups.pop()
required = parser.add_argument_group('required arguments')
optional = parser.add_argument_group('optional arguments')
required.add_argument('-n', '--name', type=allowed_name, required=True)
required.add_argument('-o', '--output', type=writable_dir_path, required=True)
optional.add_argument('-i', '--input', type=readable_dir_path, default=os.path.expandvars('$LLVM_SOURCE_DIR/mlir/examples/standalone'))
args = parser.parse_args()

def replace_name(input: str, oldname: str, newname: str):
    input = input.replace(oldname, newname)
    input = input.replace(oldname.capitalize(), newname.capitalize())
    input = input.replace(oldname.upper(), newname.upper())
    return input

def main(name: str, outdir: str, indir: str):
    if os.path.exists(outdir):
        shutil.rmtree(outdir)
    shutil.copytree(indir, outdir)

    with open(os.path.join(outdir, "CMakeLists.txt"), 'r') as file:
        oldname = re.search(r"project\(([a-z][a-z0-9]*)\-dialect", file.read()).group(1)

    for root, dirs, files in os.walk(outdir):
        for i, filename in enumerate(files):
            filepath = os.path.join(root, filename)

            with open(filepath, 'r') as file:
                filedata = file.read()
            with open(filepath, 'w') as file:
                file.write(replace_name(filedata, oldname, name))

            files[i] = replace_name(filename, oldname, name)
            os.rename(filepath, os.path.join(root, files[i]))

        for i, dirname in enumerate(dirs):
            dirs[i] = replace_name(dirname, oldname, name)
            os.rename(os.path.join(root, dirname), os.path.join(root, dirs[i]))

main(args.name, args.output, args.input)