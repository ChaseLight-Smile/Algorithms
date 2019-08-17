# -*- mode: python ; coding: utf-8 -*-

block_cipher = None


a = Analysis(['spectral-clustering.py'],
             pathex=['C:\\Users\\朱君鹏\\Desktop\\Algorithms\\GraphAlgorithms\\undirected graph clustering algorithms\\completed'],
             binaries=[],
             datas=[],
             hiddenimports = ['pandas._libs.tslibs.timedeltas','sklearn.neighbors.quad_tree', 'sklearn.tree', 'sklearn.tree._utils', 'sklearn.neighbors.typedefs', 'sklearn.utils._cython_blas'],
             hookspath=[],
             runtime_hooks=[],
             excludes=[],
             win_no_prefer_redirects=False,
             win_private_assemblies=False,
             cipher=block_cipher,
             noarchive=False)
pyz = PYZ(a.pure, a.zipped_data,
             cipher=block_cipher)
exe = EXE(pyz,
          a.scripts,
          a.binaries,
          a.zipfiles,
          a.datas,
          [],
          name='spectral-clustering',
          debug=False,
          bootloader_ignore_signals=False,
          strip=False,
          upx=True,
          upx_exclude=[],
          runtime_tmpdir=None,
          console=True )
